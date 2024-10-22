#! /usr/bin/python3

Import("env")

env.AddPostAction(
    "$BUILD_DIR/${PROGNAME}.elf",
    env.VerboseAction(" ".join([
        "arm-none-eabi-objdump", "-d", "-S",
        "$BUILD_DIR/${PROGNAME}.elf", ">", "$BUILD_DIR/${PROGNAME}.lst"
    ]), "Building $BUILD_DIR/${PROGNAME}.lst")
    )
