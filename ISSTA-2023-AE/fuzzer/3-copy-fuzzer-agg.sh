#!/bin/bash
src_folder=$1 
llvm_folder=$2
working_folder=$3
mutators_code=$src_folder/mutator_zips-v4	# increase version when updating

## Folders to edit
clang_folder=$llvm_folder/llvm-source/tools/clang
clang_tools=$llvm_folder/llvm-source/tools/clang/tools
clang_tooling=$clang_folder/include/clang/Tooling
clang_fuzzer_folder=$llvm_folder/llvm-source/tools/clang/tools/clang-fuzzer

if [ ! -d $clang_folder ]; then
  echo ">> ERROR: folder clang_folder <$clang_folder> does not exists"
  exit
fi
if [ ! -d $clang_tools ]; then
  echo ">> ERROR: folder clang_tools <$clang_tools> does not exists"
  exit
fi
if [ ! -d $clang_tooling ]; then
  echo ">> ERROR: folder clang_tooling <$clang_tooling> does not exists"
  exit
fi
if [ ! -d $clang_fuzzer_folder ]; then
  echo ">> ERROR: folder clang_fuzzer_folder <$clang_fuzzer_folder> does not exists"
  exit
fi

## backup original code & rename for current location installation
mv $clang_fuzzer_folder/ClangFuzzer.cpp $clang_fuzzer_folder/ClangFuzzer.cpp.orig
cp $mutators_code/clang-fuzzer/ClangFuzzer.cpp $clang_fuzzer_folder/
sed -i "s:/home/user42/llvm-project:$llvm_folder:g" "$clang_fuzzer_folder/ClangFuzzer.cpp"
sed -i "s:/home/user42/remove-parens:$working_folder/../remove-parens:g" "$clang_fuzzer_folder/ClangFuzzer.cpp"
sed -i "s:/home/user42/settings.txt:$working_folder/settings.txt:g" "$clang_fuzzer_folder/ClangFuzzer.cpp"
sed -i "s:/home/user42/setB:$working_folder/setB:g" "$clang_fuzzer_folder/ClangFuzzer.cpp"

mv $clang_tooling/CommonOptionsParser.h $clang_tooling/CommonOptionsParser.h.orig
cp $src_folder/../CommonOptionsParser.h $clang_tooling

mv $clang_fuzzer_folder/CMakeLists.txt $clang_fuzzer_folder/CMakeLists.txt.orig
cp $mutators_code/clang-fuzzer/CMakeLists.txt $clang_fuzzer_folder/

cp $mutators_code/clang-fuzzer/CustomClangFuzzer.h $clang_fuzzer_folder/

## copy our fuzzer
cp -r $mutators_code/assignment-mutator $clang_tools/
cp -r $mutators_code/clang-fuzzer $clang_tools/
cp -r $mutators_code/constant-mutator $clang_tools/
cp -r $mutators_code/delete-mutator $clang_tools/
cp -r $mutators_code/duplicate-mutator $clang_tools/
cp -r $mutators_code/expression-mutator $clang_tools/
cp -r $mutators_code/function-extractor $clang_tools/
cp -r $mutators_code/function-merger $clang_tools/
cp -r $mutators_code/jump-mutator $clang_tools/
cp -r $mutators_code/random-manager $clang_tools/
cp -r $mutators_code/rename-transform $clang_tools/

## copy includes for fuzzing
cp -r $src_folder/../llvm-fuzzer-includes/ $llvm_folder/

## Edit the setting file
echo "mutator_path:$llvm_folder/llvm-fuzzer-build/" > $working_folder/settings.txt
echo "lib_paths:$llvm_folder/llvm-fuzzer-includes/	/usr/include/x86_64-linux-gnu/	" >> $working_folder/settings.txt
echo "compilation_flags:-O3" >> $working_folder/settings.txt

## Copy init corpus
cp -r $src_folder/../../data/set* $working_folder/

## Edit the cmake
while IFS= read -r mt
do
   echo "add_subdirectory(tools/$mt)" >> $clang_folder/CMakeLists.txt
done < "$src_folder/mutators_agg.list"
echo ">> Done."
