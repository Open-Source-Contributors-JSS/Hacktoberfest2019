# Lines count, changable.
PYRAMID_HEIGHT = 6
# Do not change the following one, it depends on the height.
PYRAMID_BASE_STARS_AMOUNT = PYRAMID_HEIGHT*2 + 1
WALL = "|"
for stars_count in range(1, PYRAMID_BASE_STARS_AMOUNT, 2):
    spaces = (PYRAMID_HEIGHT-stars_count/2) * " "
    stars = stars_count * "*"
    print(WALL + spaces + stars + spaces + WALL)
