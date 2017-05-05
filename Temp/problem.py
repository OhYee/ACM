#coding:gbk
import re
import time
import urllib.request

# ��ʽ
str1="""
{% fold �����/����Ŀ %}
<div class="oj"><div class="part" title="Description">
$
</div><div class="part" title="Input">
$
</div><div class="part" title="Output">
$
</div><div class="samp"><div class="clear"></div><div class="input part" title="Sample Input">
$
</div><div class="output part" title="Sample Output">
$
</div><div class="clear"></div></div></div>
{% endfold %}"""


# ɾ������
def d1(str):
    str = str.strip()
    str = str.replace('\n\n','\n')
    return str+'\n'

def d2(str):
    return d1(str)

# ĩβ�������ո�  ����Ҫ��
def k(str):
    # p = re.compile(r'\n')
    # line = p.split(str)
    # str=''
    # for i in range(0,len(line)):
    #     str+=line[i]+'  \n'
    return str

# ��ȡʱ��
def GetNowTime():
    return time.strftime("%Y-%m-%d %H:%M:%S",time.localtime(time.time()))



#====================================#
#               main                 #
#====================================#

# ��������
str2 = ''
f = open('problem.txt','r',encoding='gbk')
while True:
    line = f.readline()
    if len(line) == 0:
        break
    str2 += line+'\n'
f.close()

p = re.compile(r'\$')
p2 = re.compile(r'Input|Output|Sample Input|Sample Output')

ss = p.split(str1)
ss2 = p2.split(str2)

str0=''

for i in range(0,5):
        ss2[i] = k(d1(ss2[i]))
else:
        ss2[i] = k(d2(ss2[i]))

for i in range(0, 5):
    str0 += ss[i] + ss2[i]
str0 += ss[5]

oj = input("����OJ����:")
num = input("������Ŀ���:")
name = input("������Ŀ����:")

title = '---\ntitle: '+oj+" "+num+"."+name+"\ndate: "+GetNowTime()+"\ncategories: "+'���'+"\ntags:\n - "+oj+"\n---\n\n# "+'��Ŀ'+"\n"

url = oj+"/"+num+"."+name+".cpp"
url = " https://github.com/OhYee/ACM.github.io/blob/master/" + urllib.request.quote(url)

code = "\n\n<!--more-->\n# ���\n\n\n\n# ����\n{% fold �����/������ %}```cpp "+ name + url+" ���뱸��\n\n```\n{% endfold %}"


# ǿ��ת��Ϊ utf8
ans = title + str0 + code
# ans = ans.encode('utf-8').decode('gbk')

f = open('problem.txt', 'w')
f.write(ans)            
f.close()          

