#!/bin/bash

# This script generates a C++98 header file with a class including default constructor,
# destructor, copy constructor, and copy assignment operator.

# Check if class name is provided
if [ $# -eq 0 ]; then
  echo "Usage: $0 ClassName"
  exit 1
fi

# Extract class name
class_name=$1

echo "----------> Creating Header file: $class_name.hpp"

sleep $(echo "scale=1; 0.5" | bc)
echo "."
sleep $(echo "scale=1; 0.5" | bc)
echo "."
sleep $(echo "scale=1; 0.5" | bc)
echo "."

# Create header file
cat << EOF > "$class_name.hpp"
#ifndef ${class_name}_HPP
# define ${class_name}_HPP

#include <iostream>

class $class_name
{
	private:
	    	// Private members

	public:
    		// Constructor
    		$class_name();

    		// Destructor
    		~$class_name();

    		// Copy Constructor
    		$class_name(const $class_name& copy);

    		// Copy Assignment Operator
    		$class_name& operator=(const $class_name& copy);
};

#endif /* ${class_name}_HPP */
EOF

echo "----------> Header file generated: $class_name.hpp"

