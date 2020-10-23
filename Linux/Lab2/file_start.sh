#!/bin/bash

touch "lvl2.cpp"

echo -e '#include <iostream>\n #include <fstream>\n #include <stdlib.h>\n' > 'lvl2.cpp'
echo -e 'int main() {\n std::ofstream fout("./lvl3.sh");' >> 'lvl2.cpp'
echo "fout << \"touch \\\"lvl4.cpp\\\"\n echo \\'#include <iostream>\\\n int main(){\\\n std::cout << \\\"Hello World\\\" << std::endl;\\\n return 0;\\\n}\\' > \\\"lvl4.cpp\\\"\n g++ lvl4.cpp -o lvl4\n chmod 777 lvl4.cpp\n ./lvl4\";" >> 'lvl2.cpp'
echo -e '\n' >> 'lvl2.cpp'
echo -e  "fout.close();\n" >> "lvl2.cpp"
echo -e "system(\"chmod 777 lvl3.sh\");\n" >> 'lvl2.cpp'
echo -e "system(\"./lvl3.sh\");\n return 0;\n}" >> 'lvl2.cpp'
chmod 777 lvl2.cpp
g++ lvl2.cpp -o lvl2
./lvl2
