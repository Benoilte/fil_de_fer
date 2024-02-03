RED="\033[0;31m"
GREEN="\033[0;32m"
BLUE="\033[0;34m"
YELLOW="\033[0;33m"
NONE="\033[0m"

echo ""
echo "Display matrix"

echo ""
echo "$YELLOW 10-2 $NONE"
echo ""
./fdf "test_maps/10-2.fdf"

echo ""
echo "$YELLOW 10-70 $NONE"
echo ""
./fdf "test_maps/10-70.fdf"

echo ""
echo "$YELLOW 20-60 $NONE"
echo ""
./fdf "test_maps/20-60.fdf"

echo ""
echo "$YELLOW 42 $NONE"
echo ""
./fdf "test_maps/42.fdf"

echo ""
echo "$YELLOW basictest $NONE"
echo ""
./fdf "test_maps/basictest.fdf"

echo ""
echo "$YELLOW elem-col $NONE"
echo ""
./fdf "test_maps/elem-col.fdf"

echo ""
echo "$YELLOW elem $NONE"
echo ""
./fdf "test_maps/elem.fdf"

echo ""
echo "$YELLOW elem2 $NONE"
echo ""
./fdf "test_maps/elem2.fdf"

echo ""
echo "$YELLOW pentenegpos $NONE"
echo ""
./fdf "test_maps/pentenegpos.fdf"

echo ""
echo "$YELLOW plat $NONE"
echo ""
./fdf "test_maps/plat.fdf"

echo ""
echo "$YELLOW pnp_flat $NONE"
echo ""
./fdf "test_maps/pnp_flat.fdf"

echo ""
echo "$YELLOW pylone $NONE"
echo ""
./fdf "test_maps/pylone.fdf"

echo ""
echo "$YELLOW pyra $NONE"
echo ""
./fdf "test_maps/pyra.fdf"

echo ""
echo "$YELLOW pyramide $NONE"
echo ""
./fdf "test_maps/pyramide.fdf"
