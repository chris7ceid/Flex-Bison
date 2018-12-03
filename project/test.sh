# Compile
make &> test_output.txt

# Test List
tests=(variables comments functions functions_with_parameter functions_with_patameters declaration_part \
  function_definition statements if_statement for_statement expressions definition_part)

# Run test
for test in ${tests[@]};
do
  ./parser tests/${test} &>> test_output.txt
  returnCode=${?}
  if [[ $returnCode == 0 ]];
  then
    echo [+] Test ${test} OK!
  else
    echo -e "[-] Test ${test} Fail! [${returnCode} error(s)]"
  fi
done

if [[ $1 == "--debug" ]]; then
  cat test_output.txt
fi
