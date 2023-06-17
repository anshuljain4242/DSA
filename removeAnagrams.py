def removeAnagrams(words):
    dic1 = {}
    dic2 = {}
    i = 1
    while(i<len(words)):
        str1 = sorted(words[i-1])
        str2 = sorted(words[i])
        if(str1 == str2):
            words.remove(words[i])
        else:
            i += 1    

    return words    
                       
words = ["a","a","c","a","e"]  
removeAnagrams(words)
print(words) 