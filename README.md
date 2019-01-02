# ImCompare

Compare images locally.

Still in developing...

# Usage

![1](./result/video/video.gif)

* Initial window with instructions.

![init.png](./result/image/init.png)

* Drag in image files directly. Move mouse cursor on images to compare local blocks at the same position.

![compare.png](./result/image/compare.png)

* Press key `S` to save local comparison results:
  * A composite image file of all local blocks with names.
    <br/>![compare_result.png](./result/image/compare_result.png)
  * A sole image file of each local block.
    <br/>![input.png](./result/image/input.png)
    <br/>![reference.png](./result/image/reference.png)

# Build

* Clone the repository with the `--recursive` flag to get all the dependencies:
```bash
$ git clone --recursive https://github.com/chaosink/imcompare.git
```

* Or use `git submodule` to get all the dependencies after cloning the repository:
```bash
$ git submodule update --init --recursive
```

* Then use Qt Creator to open `src/imcompare.pro` and build.
