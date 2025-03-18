import os

from pbxproj import XcodeProject
from pbxproj.pbxsections.PBXFileReference import PBXFileReference

project = XcodeProject.load("./hspInputTest/hspproj.xcodeproj/project.pbxproj")

project.add_file("CustomTextInputView.mm")
project.add_file("CustomTextInputView.h")

project.save()
