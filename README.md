# OGaBox

### Compile using a specific POCO library version

##### Unix like systems:

First we compile the POCO library with an install prefix as the following example shows.

```
cmake -DCMAKE_INSTALL_PREFIX:PATH=/home/myUser/libs/poco .
make
make install
```

When POCO is compiled sucessfully we now can compile the OGaBox project by specifying the POCO install prefix as USE_POCO_DIR.

```
cmake -DUSE_POCO_DIR:PATH=/home/myUser/libs/poco .
make
```

