#!/bin/bash

# ============
# Libft tester
# ============

LIBFT_DIR=".."
LIB="$LIBFT_DIR/libft.a"
TEST_DIR="./mains"
BUILD_DIR="./build"

GREEN="\033[92m"
GREY="\033[90m"
BLACK_ON_GREEN="\033[1;30;102m"
WHITE_ON_RED="\033[1;37;41m"
ITALIC_BLUE="\033[3;34m"
ITALIC_BLUE_BOLD="\033[3;34;1m"
ITALIC_PURPLE="\033[3;35m"
BOLD_PURPLE="\033[35;1m"
RED="\033[91m"
BOLD_RED="\033[91;1m"
RESET="\033[0m"
start=$(date +%s)
#: <<'END_COMMENT'
mkdir -p "$BUILD_DIR"
: > "$BUILD_DIR/libft_build.log"
: > "$BUILD_DIR/res_log.txt"

: <<'END_COMMENT'
			Welcome
				to
					 _ _ _
					||   ||
					||	 ||
					||   ||
					||   |\			  ||
					||   \\____		  || ||
					||		   \\   __|| ||__
					||         || //		 \\	
					|\_________// \\_________//



END_COMMENT

# =======================================================================================
# =======================================================================================
# BUILDING LIBFT
# =======================================================================================
# =======================================================================================
echo -e "${ITALIC_PURPLE}########################################################${RESET}"
echo -e "${ITALIC_PURPLE}          Testing Makefile ...  ${RESET}"
echo -e "${ITALIC_PURPLE}########################################################${RESET}\n"
#------------------Test Makefile-------------------#
echo -ne "${GREY}Makefile:"
if [ ! -f "$LIBFT_DIR/Makefile" ]; then
    echo -e "${RED}\t\t ✗ Missing!${RESET}"
    exit 1
fi
echo -e "${GREEN}\t\t ✓ ${GREY}Found!${RESET}"
#------------------Test libft.a-------------------#
echo -en "${GREY}\tMaking libft.a:${RESET}"

make -qC "$LIBFT_DIR" -s libft.a >> "$BUILD_DIR/libft_build.log" 2>&1
STATUS=$?
if [ $STATUS -eq 2 ]; then
	echo -e "${RED}\t✗ Make libft.a not found!${RESET}"
	exit 1
fi

make -C "$LIBFT_DIR" -s libft.a >> "$BUILD_DIR/libft_build.log" 2>&1

for SRC in "$LIBFT_DIR"/*.c; do
    if [[ $(basename "$SRC") == ft_lst* ]]; then
        continue
    fi

    OBJ="${SRC%.c}.o"
    if [ ! -f "$OBJ" ]; then
        echo -e "${RED}\t\t✗ Missing object file: $(basename "$OBJ")${RESET}"
        exit 1
    fi
done
if [ ! -f "$LIBFT_DIR/libft.a" ]; then
        echo -e "${RED}\t✗ Missing object file: libft.a${RESET}"
        exit 1
fi

echo -e "${GREEN}\t ✓ ${GREY}Completed!${RESET}"
#------------------Test all-------------------#
echo -en "${GREY}\tMaking all:${RESET}"

rm -f "$LIBFT_DIR"/*.o "$LIBFT_DIR"/libft.a
make -qC "$LIBFT_DIR" -s all 
STATUS=$?
if [ $STATUS -eq 0 ]; then
	echo -e "${RED}\t✗ Make all not found!${RESET}"
	exit 1
fi

make -C "$LIBFT_DIR" -s all >> "$BUILD_DIR/libft_build.log" 2>&1

for SRC in "$LIBFT_DIR"/*.c; do
    if [[ $(basename "$SRC") == ft_lst* ]]; then
        continue
    fi

    OBJ="${SRC%.c}.o"
    if [ ! -f "$OBJ" ]; then
        echo -e "${RED}\t✗ Missing object file: $(basename "$OBJ")${RESET}"
        exit 1
    fi
done
if [ ! -f "$LIBFT_DIR/libft.a" ]; then
        echo -e "${RED}\t✗ Missing object file: libft.a${RESET}"
        exit 1
fi

echo -e "${GREEN}\t ✓ ${GREY}Completed!${RESET}"
#------------------Test clean-------------------#
echo -en "${GREY}\tMaking clean:${RESET}"

make -qC "$LIBFT_DIR" -s clean 
STATUS=$?
if [ $STATUS -eq 0 ]; then
	echo -e "${RED}\t✗ Make clean not found!${RESET}"
	exit 1
fi

make clean -C "$LIBFT_DIR" -s >> "$BUILD_DIR/libft_build.log" 2>&1

NUM_OBJ=$(find "$LIBFT_DIR" -name "*.o" | wc -l)
NUM_OBJ=${NUM_OBJ:-0}

if [ "$NUM_OBJ" -ne 0 ]; then
	echo -e "${RED}\t ✗ FAIL!${RESET}"
	exit 1
fi

if [ ! -f "$LIBFT_DIR/libft.a" ]; then
        echo -e "${RED}\t✗ Missing object file: libft.a${RESET}"
        exit 1
fi

echo -e "${GREEN}\t ✓ ${GREY}Completed!${RESET}"
#------------------Test fclean-------------------#
echo -en "${GREY}\tMaking fclean:${RESET}"

make -qC "$LIBFT_DIR" -s fclean 

STATUS=$?
if [ $STATUS -eq 0 ]; then
	echo -e "${RED}\t✗ Make fclean not found!${RESET}"
	exit 1
fi

make all -C "$LIBFT_DIR" -s >> "$BUILD_DIR/libft_build.log" 2>&1

make fclean -C "$LIBFT_DIR" -s >> "$BUILD_DIR/libft_build.log" 2>&1

NUM_OBJ=$(find "$LIBFT_DIR" \( -name "*.o" -o -name "libft.a" \) | wc -l)
NUM_OBJ=${NUM_OBJ:-0}

if [ "$NUM_OBJ" -ne 0 ]; then
	echo -e "${RED}\t ✗ FAIL!${RESET}"
	exit 1
fi

echo -e "${GREEN}\t ✓ ${GREY}Completed!${RESET}"
#------------------Test re-------------------#
echo -en "${GREY}\tMaking re:${RESET}"

make -qC "$LIBFT_DIR" -s re

STATUS=$?
if [ $STATUS -eq 0 ]; then
	echo -e "${RED}\t✗ Make re not found!${RESET}"
	exit 1
fi

make -C "$LIBFT_DIR" -s re >> "$BUILD_DIR/libft_build.log" 2>&1

for SRC in "$LIBFT_DIR"/*.c; do
    if [[ $(basename "$SRC") == ft_lst* ]]; then
        continue
    fi

    OBJ="${SRC%.c}.o"
    if [ ! -f "$OBJ" ]; then
        echo -e "${RED}\t✗ Missing object file: $(basename "$OBJ")${RESET}"
        exit 1
    fi
done
if [ ! -f "$LIBFT_DIR/libft.a" ]; then
        echo -e "${RED}\t✗ Missing object file: libft.a${RESET}"
        exit 1
fi

echo -e "${GREEN}\t ✓ ${GREY}Completed!\n${RESET}"

read -p "press enter to continue to Part 1 ..."
echo -ne "\033[1A"
echo -ne "\033[2K"

#END_COMMENT
# =======================================================================================
# =======================================================================================
# TESTING libft.h
# =======================================================================================
# =======================================================================================
echo -e "${ITALIC_PURPLE}########################################################${RESET}"
echo -e "${ITALIC_PURPLE}          Testing libft.h ..."
echo -e "${ITALIC_PURPLE}########################################################${RESET}"

	norminette -R CheckDefine "$LIBFT_DIR/libft.h" >> "$BUILD_DIR/libft_build.log" 2>&1
	if [ $? -ne 0 ]; then
        echo -e "${RED}✗ [0] Norm error!${RESET}\n"
        echo -e "libft.h Norm error! 0" >> "$BUILD_DIR/res_log.txt"
		echo -e "${WHITE_ON_RED} FAIL ${RESET}${ITALIC_BLUE} libft.h ${RESET}\n"
	elif :; then
		echo -e "${GREEN}✓ [0] ok! :D${RESET}\n"
        echo -e "libft.h ok :D 1" >> "$BUILD_DIR/res_log.txt"
		echo -e "${BLACK_ON_GREEN} PASSED ${RESET}${ITALIC_BLUE} libft.h ${RESET}\n"
    fi

# =======================================================================================
# =======================================================================================
# TESTING PART 1 + PART 2
# =======================================================================================
# =======================================================================================
echo -e "${ITALIC_PURPLE}########################################################${RESET}"
echo -e "${ITALIC_PURPLE}          Testing PART 1 ..."
echo -e "${ITALIC_PURPLE}########################################################${RESET}"
for TEST_SRC in Part1/main_ft_*.c; do
	FUNC_NAME=$(basename "$TEST_SRC")
    FUNC_NAME=${FUNC_NAME#main_}
	FUNC_NAME=${FUNC_NAME%.c}

    echo -e "${ITALIC_BLUE}     ----------------------------------------------     ${RESET}"
    echo -e "${ITALIC_BLUE}          Testing ${ITALIC_BLUE_BOLD}${FUNC_NAME}${RESET}${ITALIC_BLUE} ...  ${RESET}"
    echo -e "${ITALIC_BLUE}     ----------------------------------------------     ${RESET}"

    cc -Wall -Wextra -Werror "$TEST_SRC" -I "$LIBFT_DIR" ../libft.a -lbsd -o testing \
        >> "$BUILD_DIR/libft_build.log" 2>&1

    if [ $? -ne 0 ]; then
        echo -e "${RED}✗ [-1] Compilation error!${RESET}\n"
        echo -e "${FUNC_NAME}.c Compilation error! 0" >> "$BUILD_DIR/res_log.txt"
		echo -e "${WHITE_ON_RED} FAIL ${RESET}${ITALIC_BLUE} ${FUNC_NAME} ${RESET}\n"
        continue
    fi
	norminette "$LIBFT_DIR/${FUNC_NAME}.c" >> "$BUILD_DIR/libft_build.log" 2>&1
	if [ $? -ne 0 ]; then
        echo -e "${RED}✗ [0] Norm error!${RESET}\n"
        echo -e "${FUNC_NAME}.c Norm error! 0" >> "$BUILD_DIR/res_log.txt"
		echo -e "${WHITE_ON_RED} FAIL ${RESET}${ITALIC_BLUE} ${FUNC_NAME} ${RESET}\n"
        continue
    fi
    ./testing
	rm -f testing
done

read -p "press enter to continue to Part 2 ..."
echo -ne "\033[1A"
echo -ne "\033[2K"

echo -e "${ITALIC_PURPLE}########################################################${RESET}"
echo -e "${ITALIC_PURPLE}          Testing PART 2 ..."
echo -e "${ITALIC_PURPLE}########################################################${RESET}"
for TEST_SRC in Part2/main_ft_*.c; do
	FUNC_NAME=$(basename "$TEST_SRC")
    FUNC_NAME=${FUNC_NAME#main_}
	FUNC_NAME=${FUNC_NAME%.c}

    echo -e "${ITALIC_BLUE}     ----------------------------------------------     ${RESET}"
    echo -e "${ITALIC_BLUE}          Testing ${ITALIC_BLUE_BOLD}${FUNC_NAME}${RESET}${ITALIC_BLUE} ...  ${RESET}"
    echo -e "${ITALIC_BLUE}     ----------------------------------------------     ${RESET}"

    cc -Wall -Wextra -Werror "$TEST_SRC" -I "$LIBFT_DIR" "$LIB" -lbsd -o testing \
        >> "$BUILD_DIR/libft_build.log" 2>&1

    if [ $? -ne 0 ]; then
        echo -e "${RED}✗ [-1] Compilation error!${RESET}\n"
        echo -e "${FUNC_NAME}.c Compilation error! 0" >> "$BUILD_DIR/res_log.txt"
		echo -e "${WHITE_ON_RED} FAIL ${RESET}${ITALIC_BLUE} ${FUNC_NAME} ${RESET}\n"
        continue
    fi
	norminette "$LIBFT_DIR/${FUNC_NAME}.c" >> "$BUILD_DIR/libft_build.log" 2>&1
	if [ $? -ne 0 ]; then
        echo -e "${RED}✗ [0] Norm error!${RESET}\n"
        echo -e "${FUNC_NAME}.c Norm error! 0" >> "$BUILD_DIR/res_log.txt"
		echo -e "${WHITE_ON_RED} FAIL ${RESET}${ITALIC_BLUE} ${FUNC_NAME} ${RESET}\n"
        continue
    fi
    ./testing
	rm -f testing
done

read -p "press enter to continue to BONUS ..."
echo -ne "\033[1A"
echo -ne "\033[2K"

# =======================================================================================
# =======================================================================================
# TESTING BONUS PART
# =======================================================================================
# =======================================================================================
echo -e "${ITALIC_PURPLE}########################################################${RESET}"
echo -e "${ITALIC_PURPLE}          Testing BONUS ...  ${RESET}"
echo -e "${ITALIC_PURPLE}########################################################${RESET}\n"
#------------------Test make bonus-------------------#
echo -en "${GREY}\tMaking bonus:${RESET}"

rm -f "$LIBFT_DIR"/*.o "$LIBFT_DIR"/libft.a
make -qC "$LIBFT_DIR" -s bonus
STATUS=$?
if [ $STATUS -eq 0 ]; then
	echo -e "${RED}\t✗ Make bonus not found!${RESET}"
	exit 1
fi

make -C "$LIBFT_DIR" -s bonus >> "$BUILD_DIR/libft_build.log" 2>&1

for SRC in "$LIBFT_DIR"/*.c; do
    OBJ="${SRC%.c}.o"
    if [ ! -f "$OBJ" ]; then
        echo -e "${RED}\t✗ Missing object file: $(basename "$OBJ")${RESET}"
        exit 1
    fi
done
if [ ! -f "$LIBFT_DIR/libft.a" ]; then
        echo -e "${RED}\t✗ Missing object file: libft.a${RESET}"
        exit 1
fi

echo -e "${GREEN}\t ✓ ${GREY}Completed!${RESET}"

for TEST_SRC in Bonus/main_ft_*.c; do
	FUNC_NAME=$(basename "$TEST_SRC")
    FUNC_NAME=${FUNC_NAME#main_}
	FUNC_NAME=${FUNC_NAME%.c}

    echo -e "${ITALIC_BLUE}     ----------------------------------------------     ${RESET}"
    echo -e "${ITALIC_BLUE}          Testing ${ITALIC_BLUE_BOLD}${FUNC_NAME}${RESET}${ITALIC_BLUE} ...  ${RESET}"
    echo -e "${ITALIC_BLUE}     ----------------------------------------------     ${RESET}"

    cc -Wall -Wextra -Werror "$TEST_SRC" -I "$LIBFT_DIR" "$LIB" -lbsd -o testing \
        >> "$BUILD_DIR/libft_build.log" 2>&1

	if [ $? -ne 0 ]; then
		cc -Wall -Wextra -Werror "$FUNC_NAME"_bonus.c -I "$LIBFT_DIR" "$LIB" -lbsd -o testing \
        >> "$BUILD_DIR/libft_build.log" 2>&1
	fi

    if [ $? -ne 0 ]; then
        echo -e "${RED}✗ [-1] Compilation error!${RESET}\n"
        echo -e "${FUNC_NAME}.c Compilation error! 0" >> "$BUILD_DIR/res_log.txt"
		echo -e "${WHITE_ON_RED} FAIL ${RESET}${ITALIC_BLUE} ${FUNC_NAME} ${RESET}\n"
        continue
    fi

	if [ -f "$LIBFT_DIR/${FUNC_NAME}_bonus.c" ]; then
		norminette "$LIBFT_DIR/${FUNC_NAME}_bonus.c" >> "$BUILD_DIR/libft_build.log" 2>&1
		if [ $? -ne 0 ]; then
        	echo -e "${RED}✗ [0] Norm error!${RESET}\n"
        	echo -e "${FUNC_NAME}.c Norm error! 0" >> "$BUILD_DIR/res_log.txt"
			echo -e "${WHITE_ON_RED} FAIL ${RESET}${ITALIC_BLUE} ${FUNC_NAME} ${RESET}\n"
        	continue
    	fi
	else
		norminette "$LIBFT_DIR/${FUNC_NAME}.c" >> "$BUILD_DIR/libft_build.log" 2>&1
		if [ $? -ne 0 ]; then
        	echo -e "${RED}✗ [0] Norm error!${RESET}\n"
        	echo -e "${FUNC_NAME}.c Norm error! 0" >> "$BUILD_DIR/res_log.txt"
			echo -e "${WHITE_ON_RED} FAIL ${RESET}${ITALIC_BLUE} ${FUNC_NAME} ${RESET}\n"
        	continue
    	fi
	fi
    ./testing
	rm -f testing
done

make fclean -C "$LIBFT_DIR" -s >> "$BUILD_DIR/libft_build.log" 2>&1
#END_COMMENT
echo -e "${ITALIC_BLUE}     --------------------------------------------------------------------     ${RESET}"
echo -e "${BOLD_PURPLE}                          Results:                            ${RESET}"
echo -e "${ITALIC_BLUE}     --------------------------------------------------------------------     ${RESET}"
count=0;
while read -r func status statuss num rest; do
    line_res="$func $status $statuss"
    if [[ $num -eq 0 ]]; then
		echo -ne "${BOLD_RED}<<${RESET}"
        echo -ne "${RED}$func $status $statuss${RESET}"
		echo -ne "${BOLD_RED}>>${RESET}"
    elif [[ $num -eq 1 ]]; then
        echo -ne " ${ITALIC_BLUE}$func${RESET} ${GREEN}$status $statuss${RESET} "
    fi
	((count++))
	if (( count % 4 == 0 )); then
        echo 
    fi
done < "./build/res_log.txt"

end=$(date +%s)

echo -e "${ITALIC_PURPLE}time passed: $((end - start)) sec ${RESET}"
