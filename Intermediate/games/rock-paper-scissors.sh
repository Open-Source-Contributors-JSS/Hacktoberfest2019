#!/bin/bash

read -d '' intro << "END"

===========================================
     Welcome to Rock, Paper, Scissors!
===========================================
END

read -d '' rock << "END"

      ROCK
     _____
    /   \\_\\_
   /        \\
   \\_________\\

END

read -d '' paper << "END"

     PAPER
      ______
     / ~~~~ /
    / ~~~~ /
   / ~~~~ /
   ------
END

read -d '' scissors << "END"

      SCISSORS
           //*
     _    //`
    |o|__//_____-
      _/// *****
     /o\\
     `*`
END



echo "$intro"
echo

playagain="y"

while [ "$playagain" = "y" -o "$playagain" = "Y" ]; do
    echo "Ready?"
    sleep 1
    printf "3 "
    sleep 0.5
    printf "2 "
    sleep 0.5
    echo "1"
    
    input=""
    while [[ ! $input =~ (r|p|s) ]]; do
        echo "(type r for rock, p for paper, or s for scissors)"
        read -rsn1 input
        echo
    done

    case $input in
        r)
            player=$rock
            ;;
        p)
            player=$paper
            ;;
        s)
            player=$scissors
            ;;
    esac

    case $(($RANDOM % 3)) in
        0)
            computer=$rock
            ;;
        1)
            computer=$paper
            ;;
        2)
            computer=$scissors
            ;;
    esac

    sleep 1

    echo "You played:"
    echo "$player"

    sleep 1

    echo "The computer played:"
    echo "$computer"

    sleep 1

    if [[ "$player" = "$rock" ]]; then
        if [[ "$computer" = "$paper" ]]; then
            echo "Computer wins!"
        elif [[ "$computer" = "$scissors" ]]; then
            echo "You win!"
        else
            echo "It's a tie!"
        fi
    fi

    if [[ "$player" = "$paper" ]]; then
        if [[ "$computer" = "$scissors" ]]; then
            echo "Computer wins!"
        elif [[ "$computer" = "$rock" ]]; then
            echo "You win!"
        else
            echo "It's a tie!"
        fi
    fi

    if [[ "$player" = "$scissors" ]]; then
        if [[ "$computer" = "$rock" ]]; then
            echo "Computer wins!"
        elif [[ "$computer" = "$paper" ]]; then
            echo "You win!"
        else
            echo "It's a tie!"
        fi
    fi
    
    read -p "Play again? (y/n)" -rsn1 playagain
    echo

done  # end loop

echo "Thanks for playing!  :)"

