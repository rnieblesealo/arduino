# Give all users R+W access to the device at given path 
# If no path was given default to the one Arduino UNO IDE on PopOS installed via Flatpak defaults to

if [ -z "$1" ];
then
  DEFAULT_DEV_PATH="/dev/ttyACM0"
  echo "Yielding device perms to $DEFAULT_DEV_PATH"
  sudo chmod a+rw "$DEFAULT_DEV_PATH"

else
  echo "Yielding device perms to $1"
  sudo chmod a+rw "$1"
fi
