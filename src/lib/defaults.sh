#!bash

SERVER_DIR="${SERVER_DIR-$CLICRAFT/srv}"

SERVER_NAME="${SERVER_NAME-minecraft}"

if [ "$SERVER_TYPE" = "bukkit" ]; then
	SERVER_JAR="${SERVER_JAR-$SERVER_DIR/craftbukkit.jar}"
	SERVER_URL="${SERVER_URL-http://cbukk.it/craftbukkit.jar}"
else
	SERVER_JAR="${SERVER_JAR-$SERVER_DIR/minecraft_server.jar}"
	SERVER_URL="${SERVER_URL-https://s3.amazonaws.com/MinecraftDownload/launcher/minecraft_server.jar}"
fi

START_COMMAND="${START_COMMAND-java -jar '$SERVER_JAR' nogui}"
DOWNLOAD_COMMAND="${DOWNLOAD_COMMAND-curl -#L -o "$SERVER_JAR" "$SERVER_URL"}"

