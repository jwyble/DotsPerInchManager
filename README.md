# DotsPerInchManager
This is a dots-per-inch (DPI) manager for C/C++ programs.

It is used to control the DPI-aware status of your GUI-based C++ software.

By default, in the manifest file, the DPI-aware status `<dotsPerInchAware>` is labeled _true_. If you want to disable DPI-aware status, change the label to _false_ (note that this is not recommended).

## Files
**dotsPerInchManager.h** - The primary header file for this DPI-aware wrapper. It includes scaling/unscaling, height, width, and pixel management.

**dotsPerInchAware.manifest** - This manifest file is used to ensure that DPI-Aware is present in a C++ program.

## Licensing
This dots-per-inch (DPI) manager is available under the [BSD 0-Clause License](https://github.com/jwyble/DotsPerInchManager/blob/main/LICENSE). Therefore, you can use it, with no restrictions, for any of your GUI-based C++ software projects.
