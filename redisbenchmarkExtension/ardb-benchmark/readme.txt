/home/users/yangjun03/LBS-DA-TEST/redisClient/easyBenchmarkTesttool/data

修改redis-benchmark.c
1.写一个函数，读取外部随机条件的文本文件， 保存到全局数组里；在main函数里启动时调用
2. 修改randomizeClientKey方法，用读取的文件内容随机选取一个代替random值
3. 确认最长的poi id字符串长度， 用个随机字符串标识

eg:  
redis-benchmark -r 10000 -n 10000 geosearch mypois mercator __rand_lat__ __rand__lon__ radius 3000 

createClient
randomizeClientKey


./redis-benchmark -h 10.81.12.112 -p 16379 -r 10000 -c 50  -n 100000  geosearch allpoi mercator aaaaaaaaaaaaaaa aaaaaaaaaaaaaaa  radius 3000
