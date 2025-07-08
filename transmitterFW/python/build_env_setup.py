Import("env")
import os
import shutil
import EdgeTXpassthrough

env.AddPreAction("upload", EdgeTXpassthrough.init_passthrough)
