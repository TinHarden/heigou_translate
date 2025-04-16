import requests
from fake_useragent import UserAgent

class WebTranslator:
    def __init__(self):
        self.session = requests.Session()
    def google_translate(self, words, source_lang='auto', target_lang='en'):
        base_url = "https://translate.google.com/translate_a/single"
        params = {
            'client': 'gtx',
            'sl': source_lang,
            'tl': target_lang,
            'dt': 't',
            'q': words
        }
        try:
            response = self.session.get(
                base_url,
                params=params,
                headers = {
                    'User-Agent': UserAgent().random,
                    'Referer': 'https://translate.google.com/'
                },
                timeout=10
            )
            if response.status_code == 200:
                rs = response.json()
                return rs[0][0][0]
            return "error"
        except Exception as e:
            return f"error：{str(e)}"