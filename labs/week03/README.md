# BS0013 Week 3 Lab — Dynamic Array

Week 3 uses the **same fork and Codespace** as Weeks 1 and 2. The new material must first be merged from the official course repository into your fork.

## 1. Save your current work

From the repository root:

```bash
git status
```

If you have uncommitted Week 1/2 work that you want to keep, commit it before updating:

```bash
git add .
git commit -m "Save work before Week 3 update"
```

## 2. Add the official repository as `upstream`

Check your remotes:

```bash
git remote -v
```

Your `origin` should point to **your fork**. If there is no `upstream` remote yet, add it once:

```bash
git remote add upstream https://github.com/ValRCS/RBS_BS0013_Data_Structures.git
```

Do not run that command again if `upstream` already exists.

## 3. Pull the Week 3 release into your fork

```bash
git switch main
git fetch upstream
git merge upstream/main
git push origin main
```

Using `merge` is intentional: your fork may already contain your own Week 1/2 commits, and those commits should be preserved.

If Git reports a conflict, run `git status`, inspect the conflicted files, and resolve the conflict before committing the merge. Do **not** delete your previous work just to make the update succeed.

## 4. Open and build Week 3

```bash
cd labs/week03
cmake -S . -B build
cmake --build build
```

The starter code is intentionally incomplete, but the project should compile before you fill the TODOs.

First run the observation programs:

```bash
./build/vector_growth
./build/reallocation_demo
```

Then implement `IntVector` in:

```text
src/int_vector.cpp
```

Follow `assignment.md` and complete `reflection.md`.

## 5. Test your implementation

Once the core implementation is complete:

```bash
cmake --build build
ctest --test-dir build --output-on-failure
bash scripts/check-week03.sh
```

`check-week03.sh` runs the public tests again under AddressSanitizer and UndefinedBehaviorSanitizer.

Do not modify `tests/public_tests.cpp` merely to make an incorrect implementation pass.

## Main Week 3 files

```text
assignment.md                 full practical instructions
include/int_vector.hpp        IntVector interface and representation
src/int_vector.cpp            TODO implementation
src/main.cpp                  small demonstration program
src/vector_growth.cpp         observe std::vector size/capacity
src/reallocation_demo.cpp     observe storage relocation
tests/public_tests.cpp        student-visible correctness checks
scripts/check-week03.sh       build + tests + sanitizer verification
reflection.md                 short conceptual answers
```
