Import("env")
import os
import shutil
import EdgeTXpassthrough

platform = env.get('PIOPLATFORM', '')
print("PLATFORM : '%s'" % platform)
target_name = env['PIOENV'].upper()
print("BUILD ENV: '%s'" % target_name)

if "_ETX" in target_name:
    env.AddPreAction("upload", EdgeTXpassthrough.init_passthrough)
