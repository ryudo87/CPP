//////////////////////////////////////////
void producer_thread()
{
  while(true)
    queue.push( produce() );
}

void SynchronizedQueue::push(Item const &i)
{
  pthread_mutex_lock(&mutex);
  
  // queue is full, so wait for consumer
  while (queue.size() == BUFFER_SIZE)
    pthread_cond_wait(&condition, &mutex);
  
  // when we get here, the queue has space
  this->queue.push_back(i);
  
  // make sure we wake a sleeping consumer
  if (queue.size() == 1)
    pthread_cond_signal(&condition);
  
  pthread_mutex_unlock(&mutex);
}

Item SynchronizedQueue::pop()
{
  pthread_mutex_lock(&mutex);
  
  // wait for something to do
  while (queue.size() == 0)
    pthread_cond_wait(&condition, &mutex);
  
  // if we get here, we have some work
  Item tmp = queue.front();
  
  // make sure we wake a sleeping producer
  if (queue.size() == BUFFER_SIZE)
    pthread_cond_signal(&condition)
    
    queue.pop_front();
  pthread_mutex_unlock(&mutex);
  return tmp;
}
//////////////////////////////////////////


// Using semaphores
semaphore fillCount = 0; // items produced
semaphore emptyCount = BUFFER_SIZE; // remaining space

producer() {
  while (true) {
    item = produceItem();
    down(emptyCount);
    putItemIntoBuffer(item);
    up(fillCount);
  }
}

consumer() {
  while (true) {
    down(fillCount);
    item = removeItemFromBuffer();
    up(emptyCount);
    consumeItem(item);
  }
}