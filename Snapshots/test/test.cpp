
#include "gtest/gtest.h"
#include "../src/SnapshotManager.h"






TEST(basic_Check, test_GenerateSnap)
{
    Particle* parts = new Particle[2];
    int** links = new int*[2];
    links[0] = new int[2];
    links[1] = new int[2];
    links[0][0] = 1;
    links[0][1] = 2;
    links[1][0] = 3;
    links[1][1] = 4;

    Snapshot snaps(parts, links);
    EXPECT_EQ(snaps.getParticleLinks(), links);
    EXPECT_EQ(snaps.getParticleList(), parts);
}


TEST(basic_Check, test_EnqDeq)
{
    Particle* parts = new Particle[2];
    int** links = new int*[2];
    links[0] = new int[2];
    links[1] = new int[2];
    links[0][0] = 1;
    links[0][1] = 2;
    links[1][0] = 3;
    links[1][1] = 4;

    Snapshot *snaps = new Snapshot(parts, links);
    SnapshotManager snappy(3);

    EXPECT_TRUE(snappy.enqueue(snaps));
    EXPECT_EQ(snappy.dequeue(), snaps);
}


TEST(basic_Check, test_EnqFull)
{
    Particle* parts = new Particle[2];
    int** links = new int*[2];
    links[0] = new int[2];
    links[1] = new int[2];
    links[0][0] = 1;
    links[0][1] = 2;
    links[1][0] = 3;
    links[1][1] = 4;

    Snapshot *snaps = new Snapshot(parts, links);
    Snapshot *snaps2 = new Snapshot(parts, links);
    Snapshot *snaps3 = new Snapshot(parts, links);
    Snapshot *snaps4 = new Snapshot(parts, links);

    SnapshotManager snappy(3);

    EXPECT_TRUE(snappy.enqueue(snaps));
    EXPECT_TRUE(snappy.enqueue(snaps2));
    EXPECT_TRUE(snappy.enqueue(snaps3));
    EXPECT_FALSE(snappy.enqueue(snaps4));
    EXPECT_EQ(snappy.dequeue(), snaps);
    EXPECT_EQ(snappy.dequeue(), snaps2);
    EXPECT_TRUE(snappy.enqueue(snaps4));
}



TEST(basic_Check, test_DeqEmpty)
{
    Particle* parts = new Particle[2];
    int** links = new int*[2];
    links[0] = new int[2];
    links[1] = new int[2];
    links[0][0] = 1;
    links[0][1] = 2;
    links[1][0] = 3;
    links[1][1] = 4;

    Snapshot *snaps = new Snapshot(parts, links);
    Snapshot *snaps2 = new Snapshot(parts, links);

    SnapshotManager snappy(3);

    EXPECT_TRUE(snappy.enqueue(snaps));
    EXPECT_EQ(snappy.dequeue(), snaps);
    bool testDeq = false;
    if(snappy.dequeue() == NULL)
        testDeq = true;
    EXPECT_TRUE(testDeq);
    EXPECT_TRUE(snappy.enqueue(snaps2));
    EXPECT_EQ(snappy.dequeue(), snaps2);

}
