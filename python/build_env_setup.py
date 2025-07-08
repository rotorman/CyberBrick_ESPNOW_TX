Import("env")
import os
import shutil
import EdgeTXpassthrough

env.Replace(UPLOADER="$PROJECT_DIR/python/external/esptool/esptool.py")
env.AddPreAction("upload", EdgeTXpassthrough.init_passthrough)
