from six.moves import urllib
import requests

def url_is_alive(url):
    """
    Checks that a given URL is reachable.
    :param url: A URL
    :rtype: bool
    """
    request = urllib.request.Request(url)
    request.get_method = lambda: 'HEAD'
    # print(request.head(url).status_code)
    try:
        urllib.request.urlopen(request,timeout=1)
        return True
    except :
        return False


if __name__ == '__main__':
    status = url_is_alive(url)
    print(status)
