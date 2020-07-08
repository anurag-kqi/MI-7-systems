
Virtual Machine:
  .VM is piece of software that allows you to install other software inside
   of it so you basically control it virtually as opposed to installing the
   software directly on the computer.
  .It runs on top of software called the hypervisor which sit between the
   hardware and the virtual machine.

Container:
  .a container is a software that allows different functionalities of an
   application independently.

Difference between VM & container:
  .Applications running on VM system can run different OS While applications running in a container share a single OS.
  .VM size is very large While the size of container is very light.
  .VM is slower than container.
  .VM uses a lot of system memory While containers require very less memory.
  .VM is more secure While containers are less secure.
  .VM’s are useful when we require all of OS resources to run various applications
	While containers are useful when we are required to maximise the running applications using minimal servers.
  .Examples of VM are: KVM, Xen, VMware	While examples of containers are:RancherOS, PhotonOS, Containers by Docker.
