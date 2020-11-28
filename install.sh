build_generator="Unix Makefiles"

# Use -G flag to set build generator
while getopts G: flag
do
    case "${flag}" in
        G)
            build_generator="${OPTARG}"
            ;;
    esac
done

# Create build directory
mkdir -p build/buildfiles

# Generate build files
cd build/buildfiles
cmake ../.. -G "$build_generator"

# Build project
case "$build_generator" in
    "Unix Makefiles")
        make
        ;;
    "Ninja")
        ninja
        ;;
    *)
        echo "Unknown build tool"
        exit 1
        ;;
esac

# Copy result file to build folder
mv passman ..
