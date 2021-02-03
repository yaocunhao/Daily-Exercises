cc=gcc
bin=proc
file_list=main.o pro.o

$(bin):$(file_list)
	$(cc) -o $@ $^

%.o:%.c
	$(cc) -c $<



.PHONY:clean
clean:
	rm -f $(bin)  $(file_list)


