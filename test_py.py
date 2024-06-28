def max_gold(a, b, m):
    if a == 0:
        # Hand of Midas cannot be used, return gold from using Refresher Orb
        return min(m // b, 1) * 160
    if b == 0:
        # Refresher Orb cannot be used, return gold from using Hand of Midas
        return min(m // a, 1) * 160
    
    # Calculate how many times Hand of Midas can be used in m seconds
    hand_of_midas_uses = m // a
    
    # Calculate how many times Refresher Orb can be used in m seconds
    refresher_orb_uses = m // b
    
    # Calculate the remaining time after using Hand of Midas as much as possible
    remaining_time = m - min(hand_of_midas_uses * a, m)
    
    # Calculate the additional gold by using Hand of Midas as much as possible
    additional_gold = min(hand_of_midas_uses, refresher_orb_uses) * 160
    
    # Calculate the maximum gold by using Hand of Midas and Refresher Orb optimally
    max_gold = hand_of_midas_uses * 160 + additional_gold
    
    return max_gold

# Read the number of test cases
T = int(input())

# Iterate through each test case
for _ in range(T):
    a, b, m = map(int, input().split())
    print(max_gold(a, b, m))
