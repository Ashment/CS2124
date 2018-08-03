

def stackRec(i):
    print i;
    try:
        stackRec(i+1);
    except:
        print("Max recursion depth reached.");
        return;


stackRec(0);
