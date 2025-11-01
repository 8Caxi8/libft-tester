#!/bin/bash

# ============
# Libft tester
# ============

cleanup() {
    if [ ! -z "$BLINK_PID" ]; then
        kill "$BLINK_PID" 2>/dev/null
        wait "$BLINK_PID" 2>/dev/null
    fi
}
trap cleanup EXIT INT TERM

LIBFT_DIR=".."
LIB="$LIBFT_DIR/libft.a"
TEST_DIR="./mains"
BUILD_DIR="./build"

GREEN="\033[92m"
ORANGE="\033[38;5;208m"
YELLOW="\033[93m"
BOLD_GREEN="\033[92;1m"
GREY="\033[90m"
BLACK_ON_GREEN="\033[1;30;102m"
WHITE_ON_RED="\033[1;37;41m"
ITALIC_BLUE="\033[3;34m"
ITALIC_BLUE_BOLD="\033[3;34;1m"
ITALIC_PURPLE="\033[3;35m"
BOLD_PURPLE="\033[35;1m"
RED="\033[91m"
PURPLE="\033[95m"
CYAN="\033[96m"
BLUE="\033[94m"
BOLD_RED="\033[91;1m"
MAGENTA="\033[35m"
RESET="\033[0m"
PINK="\033[95;1m"
start=$(date +%s)

declare -i command=1

mkdir -p "$BUILD_DIR"
: > "$BUILD_DIR/libft_build.log"
: > "$BUILD_DIR/res_log.txt"

#------------------Test libft.a-------------------#
makelib() {
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
}
#------------------Test all-------------------#
makeall() {
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
}
#------------------Test clean-------------------#
makeclean() {
echo -en "${GREY}\tMaking clean:${RESET}"

make -qC "$LIBFT_DIR" -s clean 
STATUS=$?
if [ $STATUS -eq 0 ]; then
	echo -e "${RED}\t✗ Make clean not found!${RESET}"
	exit 1
fi

make all -C "$LIBFT_DIR" -s >> "$BUILD_DIR/libft_build.log" 2>&1

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
}
#------------------Test fclean-------------------#
makefclean() {
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
}
#------------------Test re-------------------#
makere() {
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
}
makefile() {
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
makelib
#------------------Test all-------------------#
makeall
#------------------Test clean-------------------#
makeclean
#------------------Test fclean-------------------#
makefclean
#------------------Test re-------------------#
makere
}
libh() {
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

}
part1() {
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
	wait $!
	rm -f testing
done
}
part2() {
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
	wait $!
	rm -f testing
done
}
bonus() {
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
	wait $!
	rm -f testing
done
}

res() {
echo > ~/.gotcha
make fclean -C "$LIBFT_DIR" -s >> "$BUILD_DIR/libft_build.log" 2>&1
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

echo -e "\n\n${ITALIC_PURPLE}running time: $((end - start)) sec ${RESET}"
}

stop() {
    read -p "press enter to continue ..."
	echo -ne "\033[1A"
	echo -ne "\033[2K"
}

runstep() {
	(( command -lt 0 )) && stop
}

if [ ! -f ~/.gotcha ]; then
	echo -e "${ITALIC_PURPLE}           welcome${RESET}"
	echo -e "${ITALIC_PURPLE}               to${RESET}"

	printf "${RED} _____          _________       ______      __________    ____________  ${RESET}\n"
	printf "${ORANGE}||   ||       //          \    /      \   /|         |\  //           \  ${RESET}\n"
	printf "${YELLOW}||   ||       \___     __//   ||  __   |  ||   ______|/  \____     ___// ${RESET}\n"
	printf "${GREEN}||   ||           \. ./       ||  \/  /   ||  ||             \  /     ${RESET}\n"
	printf "${CYAN}||   ||           || ||       ||     /    ||  ||___          || |      ${RESET}\n"
	printf "${BLUE}||   |\____       || ||       ||   <      ||    ___]         || |      ${RESET}\n"
	printf "${PURPLE}||        \ \   __/' ' \___   ||  __ \    ||  ||             || |      ${RESET}\n"
	printf "${MAGENTA}||         || //           \  ||  \/  |   ||  ||            /|| |\     ${RESET}\n"
	printf "${PINK}|\________//  \___________//   \_____/    ||__||           /||| ||\    ${RESET}\n"

	echo ""
	echo ""
	echo -ne "\r${BOLD_GREEN}Press enter to continue to start the test ...${RESET}\r"
	sleep 1

	while true; do
		echo -ne "\r${BOLD_GREEN}Press enter to continue to start the test ...${RESET}\r"
		sleep 0.5
		echo -ne "\r                                                                   \r"
		sleep 0.5
	done &
	BLINK_PID=$!
	read -p ""
	cleanup 

	echo -ne "\033[1A"
	echo -e "\r${GREY}Press enter to continue to start the test ...${RESET}\r"
	echo -ne "${BOLD_RED}\tWait ...                          ${RESET}"
	sleep 0.5
	echo -e "${GREY}\r\tWait ...                                ${RESET}\r"
	sleep 1

	echo -ne "\r${BOLD_GREEN}Sorry I wasn't ready, now you can go ... ${RESET}\r"
	sleep 1
	while true; do
		echo -ne "\r${BOLD_GREEN}Sorry I wasn't ready, now you can go ... ${RESET}\r"
		sleep 0.5
		echo -ne "\r                                                              \r"
		sleep 0.5
	done &
	BLINK_PID=$!
	read -p ""
	cleanup 

	echo -ne "\033[1A"
	echo -e "\r${GREY}Sorry I wasn't ready, now you can go ... ${RESET}\r"
	echo -ne "${BOLD_RED}\tWait ...                          ${RESET}"
	sleep 0.5
	echo -e "${GREY}\r\tWait ...                                ${RESET}\r"
	sleep 1
	while true; do
		echo -ne "\r${BOLD_GREEN}\t\tAre you really ready ?? ${RESET}\r"
		sleep 0.5
		echo -ne "\r                                                 \r"
		sleep 0.5
	done &
	BLINK_PID=$!
	read -p ""
	cleanup 

	echo -ne "\033[1A"
	echo -ne "\r${GREY}\t\tAre you really ready ?? ${RESET}\r"

	while true; do
		echo -ne "\r${GREY}\t\tAre you really ready ${RESET}${BOLD_PURPLE}=>${RESET}${BOLD_RED} Really ???${RESET}\r"
		sleep 0.5
		echo -ne "\r${GREY}\t\tAre you really ready ${RESET}${BOLD_PURPLE}=>${RESET}                               \r"
		sleep 0.5
	done &
	BLINK_PID=$!
	read -p ""
	cleanup 

	echo -ne "\033[1A"
	echo -e "\r${GREY}\t\tAre you really ready => Really ???${RESET}\r"
	echo -e "\r${ITALIC_PURPLE}You will not see this message again, so enjoy!! :D and ${RESET}${BOLD_GREEN}GOOD LUCK!${RESET}\r"
	sleep 1
	read -p "press enter to continue to start the test ..."
	echo -ne "\033[1A"
	echo -ne "\033[1A"
	echo -ne "\r${GREY}\t(You will not see this message again, so enjoy!! :D and ${RESET}${BOLD_GREEN}GOOD LUCK!${RESET}\r"
	echo -e "\033[2K"
fi

for arg in "$@"; do
    [[ "$arg" == -*m* ]] && (( command *= 2 ))
    [[ "$arg" == -*l* ]] && (( command *= 3 ))
	[[ "$arg" == -*p1* ]] && (( command *= 5 ))
	[[ "$arg" == -*p2* ]] && (( command *= 7 ))
	[[ "$arg" == -*b* ]] && (( command *= 11 ))
    [[ "$arg" == -*s* ]] && (( command > 0 )) && (( command *= -1 ))
done

stop() {
    read -p "press enter to continue ..."
	echo -ne "\033[1A"
	echo -ne "\033[2K"
}

run_step() {
	"$@"
	(( command < 0 )) && stop
}

if (( command == 1 )) || (( command == -1 )); then
	run_step makefile
	libh
	run_step part1
	run_step part2
	bonus
else
	(( command % 2 == 0 )) && run_step makefile
	(( command % 3 == 0 )) && libh
	(( command % 5 == 0 )) && makelib
	(( command % 5 == 0 )) && run_step part1
	(( command % 7 == 0 )) && makelib
	(( command % 7 == 0 )) && run_step part2
	(( command % 11 == 0 )) && bonus
fi
res
