win_cond = {'R' : 'P', 'P' : 'S', 'S' : 'R'}
def find_sol(conts, counter):
    moves = []
    to_pop = []
    for i in range(len(conts)):
        try:
            moves.append(conts[i][counter])
        except:
            index = counter%len(conts[i])
            moves.append(conts[i][index])
    set_moves = set(moves)
    if len(set_moves) == 3:
        return False
    elif len(set_moves) == 2:
        temp = list(set_moves)
        move = None
        if win_cond[temp[0]] == temp[-1]:
            move = temp[-1]
        else:
            move = temp[0]
        win_moves.append(move)
        for m in range(len(moves)):
            if moves[m] != move:
                to_pop.append(m)   
    else:
        win_moves.append(win_cond[moves[0]])
        conts.clear()
        return True
    for index in sorted(to_pop, reverse=True):
        del conts[index]
    return True
def find_sol_util():
    counter = 0
    while(True):
        if len(conts) == 0:
            return True
        elif find_sol(conts, counter) == False:
            return False
        counter += 1
    return True
for t in range(int(input())):
    n_conts = int(input())
    conts = []
    for i in range(n_conts):
        conts.append(input())
    win_moves = []
    if find_sol_util():
        print("Case #" + str(t+1) + ": " + "".join(win_moves))
    else:
        print("Case #" + str(t+1) + ": " + "IMPOSSIBLE")