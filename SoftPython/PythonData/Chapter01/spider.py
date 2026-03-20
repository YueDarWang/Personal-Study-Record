#标准库：随着python安装放在安装路径的lib文件夹中。直接import
#第三方库：需要自己install uninstall update。利用pip包管理器。先安装，再import
import re
import requests

url = "https://movie.douban.com/top250"
header = {
    'user-agent':
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/146.0.0.0 Safari/537.36 Edg/146.0.0.0"
}
res = requests.get(url,headers=header)
content =res.text
#上面是从网络爬取的数据，下面要解析数据
reg = r'<div class="item">.*?<span class="title">(.*?)</span>.*?<span>(.*?)</span>'
movies = re.finditer(reg,content,re.S)
for movie in movies:
    print(movie.group(1),movie.group(2))