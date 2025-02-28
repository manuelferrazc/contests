while True:
    try:
        s=input()
        s=input()
        if s[0]=="S":
            print("facochero")
        elif s[0]=="O":
            print("leao")
        else:
            print("suricato")

    except EOFError:
        break