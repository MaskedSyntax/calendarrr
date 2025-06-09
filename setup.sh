#!/bin/bash

# Move the binary to /usr/local/bin
sudo cp bin/calendarrr /usr/local/bin/calendarrr

# Create the applications directory if it doesn't exist
mkdir -p ~/.local/share/applications/

# Create the desktop entry
cat <<EOL > ~/.local/share/applications/calendarrr.desktop
[Desktop Entry]
Version=1.0
Type=Application
Name=Calendarrr
Comment=A minimal calendar application
Exec=/usr/local/bin/calendarrr
Icon=calendarrr-outlined
Terminal=false
Categories=Utility;Application;
EOL

# Move the icons to the appropriate directory
mkdir -p ~/.local/share/icons/hicolor/scalable/apps/
cp docs/assets/calendarrr-outlined.svg ~/.local/share/icons/hicolor/scalable/apps/calendarrr-outlined.svg
cp docs/assets/calendarrr.svg ~/.local/share/icons/hicolor/scalable/apps/calendarrr.svg

# Update the icon cache
gtk-update-icon-cache ~/.local/share/icons/hicolor

echo "Setup complete! You can now run Calendarrr from your application menu."

