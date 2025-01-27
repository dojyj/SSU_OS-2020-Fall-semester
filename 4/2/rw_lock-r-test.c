#include "rw_lock.h"

void init_rwlock(struct rw_lock * rw)
{
  //	Write the code for initializing your read-write lock.
	rw->read_bit = 0;
	rw->write_bit = 0;
	rw->read_amount = 0;
}

void r_lock(struct rw_lock * rw)
{
  //	Write the code for aquiring read-write lock by the reader.
	if (rw->read_amount == 0)
		rw->read_bit = 1;
	rw->read_amount++;
}

void r_unlock(struct rw_lock * rw)
{
  //	Write the code for releasing read-write lock by the reader.
	rw->read_amount--;
	if (rw->read_amount == 0)
		rw->read_bit = 0;
}

void w_lock(struct rw_lock * rw)
{
  //	Write the code for aquiring read-write lock by the writer.
	while (1){
		if (rw->read_bit == 0 && rw->write_bit == 0){
			break;
		}

		usleep(100);
	}

	rw->write_bit = 1;
}

void w_unlock(struct rw_lock * rw)
{
  //	Write the code for releasing read-write lock by the writer.
	rw->write_bit = 0;
}
