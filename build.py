#!/usr/bin/python3

import glob
import sys
import os
import subprocess
import shutil
import hashlib
import colorama
from typing import List

BUILD_DIR: str = 'build'
TOOLS_DIR: str = 'tools'
BASENAME: str = 'customrobo'
SPLAT: str = f'{TOOLS_DIR}/splat/split.py'
M2CTX: str = f'{TOOLS_DIR}/m2ctx.py'
ASMPROCESSOR: str = f'{TOOLS_DIR}/asm-processor/asm_processor.py'
REMCOMS: str = f'{TOOLS_DIR}/clearcomments.py'
N64CRC: str = f'{TOOLS_DIR}/n64crc'
FIRSTDIFF: str = 'first_diff.py'
PYTHON: str = 'python3'

def verify_checksum(bin_file: str, sha1sum_file: str) -> bool:
    # Read the SHA1 checksum from the binary file
    with open(bin_file, 'rb') as f:
        sha1 = hashlib.sha1()
        while True:
            data = f.read(65536)
            if not data:
                break
            sha1.update(data)
        bin_checksum = sha1.hexdigest()

    # Read the SHA1 checksum from the file that contains the checksum
    with open(sha1sum_file, 'r') as f:
        file_checksum = f.readline().split()[0]

    # Compare the checksums and return the result
    if bin_checksum == file_checksum:
        return True
    else:
        return False

# I decided that I hate Ninja
def read_build_ninja_original() -> List[str]:
    with open('build.ninja_', 'r') as original_file:
        lines = original_file.readlines()
        for i, line in enumerate(lines):
            lines[i] = line.replace('__BASENAME__', BASENAME)
            if line.startswith('PYTHON = PYTHON_VALUE'):
                lines[i] = f'PYTHON = {PYTHON}\n'
        return lines

def generate_build_ninja(permuter: bool) -> None:
    c_files = glob.glob('src/**/*.c', recursive = True)
    asm_files = [file for file in glob.glob('asm/**/*.s', recursive = True) + glob.glob('src/**/*.s', recursive = True) if 'asm/nonmatchings' not in file]
    bin_files = glob.glob('assets/**/*.bin', recursive = True)

    output_lines = read_build_ninja_original()
    o_files = []

    for c_file in c_files:
        obj_file = os.path.join('build', c_file + '.o')
        if not permuter:
            output_lines.append(f'build {BUILD_DIR}/{c_file}.d: compile_c_cpp {c_file}\n')
            output_lines.append(f'build {obj_file}: compile_c {c_file} | {BUILD_DIR}/{c_file}.d\n')
        else:
            output_lines.append(f'build {obj_file}: compile_c {c_file}\n')
        o_files.append(obj_file)
        os.makedirs(os.path.join('build', os.path.dirname(c_file)), exist_ok = True)

    for asm_file in asm_files:
        obj_file = os.path.join('build', asm_file + '.o')
        output_lines.append(f'build {obj_file}: assemble_s {asm_file}\n')
        o_files.append(obj_file)
        os.makedirs(os.path.join('build', os.path.dirname(asm_file)), exist_ok = True)

    for bin_file in bin_files:
        obj_file = os.path.join('build', bin_file + '.o')
        output_lines.append(f'build {obj_file}: compile_bin {bin_file}\n')
        o_files.append(obj_file)
        os.makedirs(os.path.join('build', os.path.dirname(bin_file)), exist_ok = True)

    o_files_str = ' '.join(o_files)
    output_lines.append(f'\nbuild {BUILD_DIR}/{BASENAME}.elf: link {o_files_str}\n')
    output_lines.append(f'build {BUILD_DIR}/{BASENAME}.z64: objcopy {BUILD_DIR}/{BASENAME}.elf\n')

    with open('build.ninja', 'w') as build_file:
        build_file.writelines(output_lines)

def invoke_ninja() -> None:
    subprocess.run(['ninja'], check = True)

# Commands

def command_initial() -> None:
    subprocess.run(['make', '-C', TOOLS_DIR], check = True)

def command_clean() -> None:
    if os.path.exists('build'):
        shutil.rmtree('build')
    for file in glob.glob('preprocessed_*'):
        os.remove(file)

def command_nuke() -> None:
    command_clean()
    if os.path.exists('asm'):
        shutil.rmtree('asm')
    if os.path.exists('assets'):
        shutil.rmtree('assets')
    autos = glob.glob('*auto.txt')
    for autofile in autos:
        try:
            os.remove(autofile)
        except:
            print(f'Failed to remove {autofile}')

def command_context() -> None:
    try:
        os.remove('ctx.c')
        os.remove('ctx_includes.c')
    except OSError:
        pass

    include_files = []
    for root, dirs, files in os.walk('include/'):
        for file in files:
            if file.endswith('.h'):
                include_files.append(os.path.join(root, file))
    for root, dirs, files in os.walk('src/'):
        for file in files:
            if file.endswith('.h'):
                include_files.append(os.path.join(root, file))

    ctxinc = 'ctx_includes.c'
    with open(ctxinc, 'w') as f:
        for include_file in include_files:
            f.write(f'#include "{include_file}"\n')
    subprocess.run([PYTHON, M2CTX, ctxinc], check=True)

def build(permuter: bool) -> None:
    generate_build_ninja(permuter)
    invoke_ninja()
    print('================')
    subprocess.run([N64CRC, f'{BUILD_DIR}/{BASENAME}.z64'])
    if verify_checksum(f'{BUILD_DIR}/{BASENAME}.z64', 'checksum.sha1'):
        print('OK!')
    else:
        print('NOT OK!!')

if __name__ == '__main__':
    colorama.init()
    PYTHON = sys.executable

    build_used = False

    args = sys.argv[1:]
    for value in args:
        trunc = value.split('=')
        arg = trunc[0]
        if arg == 'initial':
            command_initial()
        if arg == 'nuke':
            command_nuke()
        if arg == 'clean':
            command_clean()
        if arg == 'setup':
            try:
                os.remove('symbol_addrs.txt')
            except:
                pass
            subprocess.run(['cpp', '-CC', '-P', 'symbol_addrs_original.txt'], stdout = open('symbol_addrs.txt', 'w'))
            subprocess.run([PYTHON, REMCOMS, 'symbol_addrs.txt'])
            subprocess.run([PYTHON, SPLAT, f'{BASENAME}.yaml'], check = True)
        if arg == 'context':
            command_context()
        if arg == 'build':
            build_used = True
            if len(trunc) > 1:
                if int(trunc[1]) == 1:
                    build(False)
            else:
                build(False)
        if arg == 'permuter':
            build_used = True
            build(True)
        if arg == 'diff':
            subprocess.run([PYTHON, FIRSTDIFF], check = True)

    if build_used == False:
        build(False)

