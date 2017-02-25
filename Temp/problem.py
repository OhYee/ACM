#coding:gbk
import re
import time
import urllib.request

# ��ʽ
str1="""{% raw %}
<div><div class="fold_hider"><div class="close hider_title">�����/����Ŀ</div></div><div class="fold">
    <div class="oj">   
        <div class="part" title="Description">
{% endraw %}
            $
{% raw %}
        </div>
        <div class="part" title="Input">
{% endraw %}
            $
{% raw %}
        </div>
        <div class="part" title="Output">
{% endraw %}
            $
{% raw %}
        </div>
        <div class="samp">
            <div class="clear"></div>
            <div class="input part" title="Sample Input">
{% endraw %}
                $
{% raw %}
            </div>
            <div class="output part" title="Sample Output">
{% endraw %}
                $
{% raw %}
            </div>
            <div class="clear"></div>
        </div>
    </div>
</div></div>
{% endraw %}"""


# ɾ������
def d1(str):
    str=str.replace('\n\n','\n')
    return str
def d2(str):
    str=str.replace('\n\n','\n')
    return str

# ĩβ�������ո�
def k(str):
    p = re.compile(r'\n')
    line = p.split(str)
    str=''
    for i in range(0,len(line)):
        str+=line[i]+'  \n'
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
    if i < 3:
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

code = "\n\n<!--more-->\n# ���\n\n\n\n# ����\n```cpp "+ name + url+" ���뱸��\n\n```"


# ǿ��ת��Ϊ utf8
ans = title + str0 + code
# ans = ans.encode('utf-8').decode('gbk')

f = open('problem.txt', 'w')
f.write(ans)            
f.close()          

