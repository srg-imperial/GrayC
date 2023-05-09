# GrayC Artifact

## Getting Started

This Docker image contains a pre-built version of GrayC. It also includes all the tools we comapred against in our controlled evaluation and includes to set ups of GrayC: aggressive and conservative modes. To start the docker container:
```
docker run -it grayc
```

### Artifact’s requirements
git, python3, python3-pip, gfauto (under Google's graphicsfuzz), cmake, m4, ninja-build, curl, wget, zip, unzip,  

Note that: CMake 3.13.4 or higher is required.

Most of the packages required can be installed with (e.g.) brew or apt, however, some need to be build from source.
1. gfauto: https://github.com/google/graphicsfuzz.git
2. 

### Steps to check the basic functionality of the artifact
todo

A copy of this README is in the working directory of the Docker image, ~/grayc/README.md.

## Detailed Instructions

Here we describe how to reproduce all the tables and graphs data for section 5 in the paper: the controlled experiments with the additionl other 8 tools compared with.

### Step-by-Step instructions

### Build from source
GrayC was implemented on top of LibFuzzer and so its build may take long, depends on your machine: it builds LLVM 12 with instrumentation.


### Project structure
