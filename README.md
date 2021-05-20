## How to test

1. Execute `./gnl.sh` to test the original version<br>
or `./gnl_v2.sh` to test modified version.

2. Run test files i.e. `./test_gnl test_files/kalevala.txt` to see the output

3. To test multiple file descriptors, run:<br>
`./test_gnl test_files/maamme.txt test_files/kalevala.txt test_files/bible_parts.txt `

4. Test with standard input i.e.<br>
`echo "12345678\n87654321" | ./test_gnl stdin` _(with newlines)_<br>
`echo -n "12345678\n87654321" | ./test_gnl stdin` _(without newlines)_

## Additional tests

_**42FILECHECKER**_<br>
`5)    project: get_next_line`<br>

_**remember to:**_<br>
`B)    change path`
