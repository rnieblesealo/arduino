# Check Arduino CLI exists
if command -v arduino-cli > /dev/null 2>&1;
then
  # Initialize config
  echo "Attempting to init config..."
  arduino-cli config init

  # Update board definitions 
  echo "Updating board definitions..."
  arduino-cli core update-index

  # Install AVR board core(s?)
  echo "Installing AVR core..."
  arduino-cli core install arduino:avr

  echo "Routine complete!"
else
  echo "Arduino CLI not found, please install it! (brew install arduino-cli...)"
fi
