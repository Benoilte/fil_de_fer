RED="\033[0;31m"
GREEN="\033[0;32m"
BLUE="\033[0;34m"
NONE="\033[0m"

echo ""
echo "CHECK NO LEAKS WITH WRONG INPUT"

echo ""
echo "$BLUE CALL PROGRAM WITHOUT ARGUMENT $NONE"
echo ""
echo "./fdf => $RED"
echo "Error: File is missing $NONE"
leaks --atExit -- ./fdf

echo ""
echo "$BLUE TOO MANY ARGUMENT $NONE"
echo ""
echo "./fdf map_1.fdf map_2.fdf => $RED"
echo "Error: Too many argument $NONE"
leaks --atExit -- ./fdf map_1.fdf map_2.fdf

echo ""
echo "$BLUE WRONG FORMAT ARG $NONE"
echo ""
echo "./fdf map.fd => $RED"
echo "Error: Unrecognized format $NONE"
leaks --atExit -- ./fdf map.fd

echo ""
echo "$BLUE FILE DOES NOT EXIST $NONE"
echo ""
echo "./fdf not_exist.fdf => $RED" 
echo "Erorr: No such file or directory $NONE"
leaks --atExit -- ./fdf not_exist.fdf

echo ""
echo "$BLUE EMPTY FILE $NONE"
echo ""
echo "./fdf test_maps/empty.fdf => $RED"
echo "Erorr: Empty file $NONE"
leaks --atExit -- ./fdf test_maps/empty.fdf
