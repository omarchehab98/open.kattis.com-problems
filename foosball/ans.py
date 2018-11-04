input()
players = input().split()
board = {"W": {}, "B": {}}
order = {"W": [], "B": []}
board["W"]["offense"] = players.pop(0)
order["W"] += [board["W"]["offense"]]
board["B"]["offense"] = players.pop(0)
order["B"] += [board["B"]["offense"]]
board["W"]["defense"] = players.pop(0)
order["W"] += [board["W"]["defense"]]
board["B"]["defense"] = players.pop(0)
order["B"] += [board["B"]["defense"]]
games = list(input())
current_dynasty = (None, 0)
longest_dynasties = ([], 0)
for winning_team in games:
    losing_team = 'B' if winning_team == 'W' else 'W'
    players += [board[losing_team]["defense"]]
    board[losing_team]["defense"] = board[losing_team]["offense"]
    board[losing_team]["offense"] = players.pop(0)
    order[losing_team] = [board[losing_team]["defense"], board[losing_team]["offense"]]
    board[winning_team]["offense"], board[winning_team]["defense"] = board[winning_team]["defense"], board[winning_team]["offense"]
    dynasty_team, dynasty_streak = current_dynasty
    longest_dynasty_teams, longest_dynasty_streak = longest_dynasties
    if dynasty_team == winning_team:
        dynasty_streak += 1
    else:
        dynasty_team = winning_team
        dynasty_streak = 1
    if dynasty_streak == longest_dynasty_streak:
        longest_dynasty_teams += [order[winning_team][0] + ' ' + order[winning_team][1]]
    elif dynasty_streak > longest_dynasty_streak:
        longest_dynasty_teams = [order[winning_team][0] + ' ' + order[winning_team][1]]
        longest_dynasty_streak = dynasty_streak
    current_dynasty = dynasty_team, dynasty_streak
    longest_dynasties = longest_dynasty_teams, longest_dynasty_streak

print('\n'.join(longest_dynasties[0]))