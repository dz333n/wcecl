import json
import sys
import os

meta_path = sys.argv[1]
compile_commands_path = sys.argv[2]

meta = {}
compile_commands = []

with open(meta_path, 'r') as file:
    meta = json.load(file)

for path, target in meta['targets'].items():
    if not 'cxx' in target.keys():
        continue

    cxx = target['cxx']
    if not 'sources' in cxx.keys():
        continue

    compiler = 'clang++'  # target['tools']['compiler']
    standard = cxx['standard']

    if standard == 'c++latest':
        standard = 'c++20'

    flags: list[str] = []

    flags += ['-x', 'c++']
    # flags += ['-std', 'c++']
    flags.append(f'-std={standard}')

    for include_dir in cxx['include_dirs']:
        flags.append(f'-I{include_dir}')

    for definition in cxx['definitions']:
        flags.append(f'-D{definition}')

    for source in cxx['sources'] + (target['unused-sources'] if 'unused-sources' in target.keys() else []):
        if os.path.splitext(source)[-1].startswith('h'):
            continue

        command = {
            'directory': path,
            'file': source,
            'arguments': [compiler] + flags + [source]
        }
        compile_commands.append(command)

with open(compile_commands_path, 'w') as file:
    json.dump(compile_commands, file)
