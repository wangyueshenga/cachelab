let var=34
let var_2=0
echo '${var} = '${var} '\t' '${var_2} = '${var_2}
./test-trans -M ${var} -N ${var} && echo "Begin to execute the tracegen program." && ./tracegen -M ${var} -N ${var} -F ${var_2}