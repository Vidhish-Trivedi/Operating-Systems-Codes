# Program Number : 01
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 15/01/2023
# Description : Create the following types of a files using (i) shell command (ii) system call
                # a. soft link (symlink system call)
                # b. hard link (link system call)
                # c. FIFO (mkfifo Library Function or mknod system call)

echo -n "Enter filename: "
read fn

echo -n "Enter name of soft link: "
read sl

echo -n "Enter name of hard link: "
read hl

echo -n "Enter name of fifo filename: "
read ff

echo "Creating soft link..."
ln -s $fn $sl
echo "Soft link created."
echo "Creating hard link..."
ln $fn $hl
echo "Hard link created."
echo "Creating FIFO..."
mkfifo -m 666 $ff
echo "FIFO file created."

