from setuptools import setup
import os
from glob import glob

package_name = 'custom_msgs'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        # Include package metadata
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # Include all message files
        (os.path.join('share', package_name, 'msg'), glob('msg/*.msg')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='sohamverma',
    maintainer_email='contact@sohamverma.com',
    description='Custom message package for ROS 2',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
          
        ],
    },
)
