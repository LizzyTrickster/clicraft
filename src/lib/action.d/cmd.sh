#!bash
#
# Usage: clicraft cmd <command>
#
#    Sends <command> to the minecraft server.
#

action status >/dev/null && \
	tmux send -t "$SERVER_NAME" "$*" C-m

