# BookSystem
  一、程序实践概述  
 1、题目名称: 《图书信息管理系统》的设计与实现   
 2、时间进度:已完成(3周) 
 3、开发环境: MAC OSX, Xcode 
  二、问题分析 
 1、功能说明:本系统录入图书信息有:书名,作者,编号,出版社,状态(已借或未借)。
    包含了五大基础板块和十一个功能的实现,整个系统除了主函数外,另外还有13个函数,,包括主函数在内,以实现  功能:图书信息浏览功能,图书信息查询 功能,图书信息录入功能,图书信息删除功能,图书信息清空功能,读者借阅管理功能,读者归还管理功能,显在借读者的信息功能,修改密码功能,帮助文档功能以及退出系统功能。 
 先登 前需要输 已注册的账号密码,输 错误将会给出提 并且 法登 界  。 
  本套系统将所有功能分为五 板块:  (1)图书信息管理 
a:图书信息展 功能:可将图书馆的书已编号升序的 式全部显 ,由 bookDisplay函数可实现。 
b:图书信息查询功能:可按书名查找图书馆中图书信息,由bookSearch函 数可实现。 
c:图书信息录 功能:输 添加 本书,并且输 书名,作者,编号,出 版社以及状态,即可向本系统录 新书信息,由bookAdd函数实现。  
d:图书信息删除功能:可删除本系统中图书信息,由bookDelete函数实现。 e:图书信息清空功能:可清空本系统中所储存的图书信息,由bookEmpty
函数实现。 
(2)读者信息管理  a:读者借阅管理功能:可对读者借阅信息(姓名,学号以及所借图书)进 记
录,由bookBorrow函数和bookStateChange函数可实现。   
b:读者归还管理功能:可对读者借阅信息更改记录,从 实现归还图书功 能,由bookReturn函数和bookStateChange函数实现 
书。    
(3)修改密码: 
