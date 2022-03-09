# zeep
Zeep is a program used to compress files

## Command Line Interface

```shell
$ zeep [options] <input_file> <output_file>
```

### Options

```text
Normal Options:
    -h, --help                  Show this help message.
    -c, --compress <type>       Compress the input file. (Default)
    -d, --decompress <type>     Decompress the input file.

Compress type:
    --huffman                   Use Huffman Coding. (Default)
    --huffman-adaptive          User Adaptive Huffman Coding.
```

### Compress File

```shell
# Compress by Huffman Coding
$ zeep --huffman <input_file> <output_file>
```

### Decompress File

```shell
$ zeep -d --huffman <input_file> <output_file>
```