import re


def word_counter(text: str) -> int:  # task 1.1
    """
    Count words in txt.
    :param text: big text
    :return: number of words
    """
    if text is None:
        return 0
    else:
        just_txt = re.sub('[!@#$/*.,+()\-\[\]]', '', text)
        words = just_txt.split()
        return len(words)


def _find_max(d: dict) -> str:
    """
    Additional func. Find key with max value.
    :return: key of dict
    """
    maxi = 0
    val = ''
    for k, v in d.items():
        if v > maxi:
            maxi = v
            val = k
    return val


def find_top10_words(text: str) -> list:  # task 1.2
    """
    Find top 10 words in txt.
    :param text: big text
    :return: storage of top words
    """
    if text is None:
        return []
    else:
        finale = list()
        stor = dict()
        visited = set()

        new_text = re.sub('[!@#$/*.,+()\-\[\]"]', '', text)
        words = new_text.split()

        for word in words:
            if word in visited:
                num = stor.get(word)
                stor[word] = num + 1
            else:
                stor[word] = 1
                visited.add(word)

        while len(finale) < 10:
            top_w = _find_max(stor)
            finale.append(top_w)
            stor.pop(top_w)
        return finale


def reverse_sentences(text: str) -> str:  # task 1.3
    new_text = ''
    arr = list()

    n_text = text.replace('"', '')
    words = n_text.split()
    for word in range(0, len(words)):
        last_l = len(words[word]) - 1
        if words[word][last_l:] in ['.', '?', '!', '!?', '...', '?!']:
            arr.append(words[word][:-1])
            for w in reversed(arr):
                new_text += w + ' '
            arr = list()
        else:
            arr.append(words[word])
    return new_text


def main():
    ####### OPEN FILE ########
    # f = open('big_text.txt', 'r')
    f = open('TEXT.txt', 'r')
    TEXT = f.read()

    ####### FUNC CALL ########
    print(word_counter(TEXT))
    print(find_top10_words(TEXT))
    print(reverse_sentences(TEXT))  ######## ИСПРАВИТЬ

    ####### CLOSE FILE #######
    f.close()


if __name__ == '__main__':
    main()
