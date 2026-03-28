#!/usr/bin/fish

set cpp_files (find include/ src/ tests/ -iname "*.[c|h]pp")

printf "Attempting to format: %s...\n\n" "$cpp_files"

if type -q clang-format
    clang-format -i $cpp_files

    echo "Succes: finished formatting."
else
    echo "Error: clang-format could not be found."
end
