from setuptools import find_packages, setup

package_name = 'robot_controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='sohamverma',
    maintainer_email='contact@sohamverma.com',
    description='Custom controller package for ROS 2',
    license='Apache-2.0',
    extras_require={
            'test': ['pytest'],
        },
    entry_points={
        'console_scripts': [
          'controller_node = robot_controller.controller_node:main',
        ],
    },
)
