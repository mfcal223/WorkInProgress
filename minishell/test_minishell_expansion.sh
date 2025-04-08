# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_minishell_expansion.sh                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 16:38:00 by mcalciat          #+#    #+#              #
#    Updated: 2025/04/08 16:56:29 by mcalciat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Usage: ./test_minishell_expansion.sh ./minishell
MINISHELL=$1

if [ ! -x "$MINISHELL" ]; then
	echo "Usage: $0 /path/to/minishell"
	exit 1
fi

TMP1=$(mktemp)
TMP2=$(mktemp)

# Test cases: each test is a command to run
TESTS=(
	"echo hello"
	"echo \$?"
	"false"
	"echo \$?"
	"idontexist"
	"echo \$?"
	"echo \$HOME"
	"echo \$HOME \$USER"
	"echo \"Welcome, \$USER!\""
	"echo '\$HOME'"
	"echo \"\$HOME\""
	"echo \"'\$HOME'\""
	"false | true"
	"echo \$?"
	"true | false"
	"echo \$?"
	"echo \$? > out.txt && cat out.txt"
	"echo \"Exit status was \$?\""
)

echo "Running tests against Bash and your Minishell..."
echo

for i in "${!TESTS[@]}"; do
	CMD="${TESTS[$i]}"
	echo "$CMD" | bash > "$TMP1" 2>&1
	echo "$CMD" | "$MINISHELL" | sed 's/^minishell\$ //' > "$TMP2" 2>&1

	echo "🔹 Test $((i+1)): $CMD"
	diff -u "$TMP1" "$TMP2" > /dev/null
	if [ $? -eq 0 ]; then
		echo "✅ Output matches"
	else
		echo "❌ Output differs:"
		echo "--- Bash"
		cat "$TMP1"
		echo "--- Minishell"
		cat "$TMP2"
	fi
	echo
done

rm "$TMP1" "$TMP2"