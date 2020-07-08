#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

main()
{
  int fd;
  char buf[100];
  int count;

  // FILE *fp = fopen("about_me.txt", "rw");
  // fread(fp, buf, 100);

  fd = open("about_me.txt", O_RDWR);
  printf("fd %d\n", fd);
  if (fd < 0) {
      perror("open failed");
  }
  lseek(fd, 10, 0);

  count = read(fd, buf, 10);
  printf("count %d\n", count);
  buf[10] = '\0';
  printf("file content is %s", buf);
  // lseek(fd, 10, 0);
  count = read(fd, buf, 10);
  printf("count %d\n", count);
  buf[10] = '\0';
  printf("file content is %s", buf);

  //
  if (count <= 0) {
      perror("read failed");
  }
  buf[99] = '\0';
  printf("file content is %s", buf);
//  close(fd);
  fd = open("about_me.txt", O_RDWR);
  printf("fd %d\n", fd);
  if (fd < 0) {
      perror("open failed");
  }

  //open, read, close
  //write
  //lseek


}
